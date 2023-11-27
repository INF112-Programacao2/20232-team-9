#include "pessoajuridica.h"
#include "contabilidade_juridica.h"

class JuridicaIndustrial: public ContabilJuridica{
private:

public:
    virtual void set_caixa();
    virtual void set_estoque();
    virtual void set_contasreceber();

};