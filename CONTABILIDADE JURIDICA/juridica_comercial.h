#ifndef JURIDICA_COMERCIAL_H
#define JURIDICA_COMERCIAL_H


#include "cadastro.h"
#include "contabilidade_juridica.h"

class Juridica_PrestServi : public ContabilJuridica{
private:



public:
    virtual void set_caixa();
    virtual void set_estoque();
    virtual void set_contasreceber();

};


#endif // JURIDICA_COMERCIAL_H