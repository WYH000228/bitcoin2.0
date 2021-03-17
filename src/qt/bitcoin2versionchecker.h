#ifndef BITCOIN2VERSIONCHECKER_H
#define BITCOIN2VERSIONCHECKER_H

#include <QObject>

#define BITCOIN2_RELEASES "https://github.com/cryptofugu/bitcoin2chain-core/releases"

class Version {

public:
    int _major;
    int _minor;
    int _revision;

    Version(){
        SetNull();
    }

    Version(int maj, int min, int rev){
        SetNull();

        _major = maj;
        _minor = min;
        _revision = rev;
    }

    Version(QString str){
        SetNull();

        QStringList parts = str.split(".");

        if(!parts.isEmpty())
            _major = parts[0].toInt();
        if(parts.length() > 1)
            _minor = parts[1].toInt();
        if(parts.length() > 2)
            _revision = parts[2].toInt();
    }

    Version(const Version &v){
        _major = v._major;
        _minor = v._minor;
        _revision = v._revision;
    }

    bool operator >(const Version& other) const
    {
        return compareAll(other) > 0;
    }

    bool operator <(const Version& other) const
    {
        return compareAll(other) < 0;
    }

    bool operator ==(const Version& other) const
    {
        return compareAll(other) == 0;
    }

    void SetNull()
    {
        _major = 0;
        _minor = 0;
        _revision = 0;
    }

private:
    int compare(int first, int second) const
    {
        int diff = first - second;
        return diff > 0 ? 1 : diff < 0 ? -1 : 0;
    }
    int compareAll(const Version& other) const
    {
        return 4 * compare(_major, other._major) +
               2 * compare(_minor, other._minor) +
               compare(_revision, other._revision);
    }
};

class BITCOIN2VersionChecker : public QObject
{
    Q_OBJECT
public:
    explicit BITCOIN2VersionChecker(QObject *parent = 0);
    ~BITCOIN2VersionChecker();

    bool newVersionAvailable();

private:
    QList<Version> getVersions();
    Version getMaxReleaseVersion();

    Version currentVersion;
};

#endif // BITCOIN2VERSIONCHECKER_H
