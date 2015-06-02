
#ifndef ADDRESSTRANSLATOR_H_
#define ADDRESSTRANSLATOR_H_


#include <map>


class AddressTranslator
{
public:
    static AddressTranslator & GetInstance();

    void AddAddress(void * oldAddress, void * newAddress);
    void * TranslateAddress(void * oldAddress);
    void Reset();
    
protected:
    AddressTranslator() {};
    
private:
    typedef std::map<int, int> AddressTable;
    AddressTable m_table;
};



#endif

