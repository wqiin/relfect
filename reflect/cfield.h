#ifndef CFIELD_H
#define CFIELD_H

#include <string>

class CField
{
public:
    CField();
    CField(const std::string strFieldName, const std::string & strFieldType, size_t nFieldOffset);
    ~CField();

    const std::string & getFieldName() const;
    const std::string & getFieldType() const;
    size_t getFieldOffset() const;

private:
    std::string m_strFieldName;
    std::string m_strFieldType;
    size_t m_nFieldOffset;
};

#endif // CFIELD_H
