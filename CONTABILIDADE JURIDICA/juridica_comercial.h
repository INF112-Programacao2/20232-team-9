#include "pessoajuridica.h"
#include "contabilidade_juridica.h"

class JuridicaComercial : public ContabilJuridica{
private:

public:
    virtual void set_caixa();
    virtual void set_estoque();
    virtual void set_contasreceber();

};
/*
// COMERCIO

// Atacado** = Simples Nacional ANEXO I
// Varejo** = Simples Nacional ANEXO I

if (valor 1 < 180){
    // aliquota 4%
    // desconto = 0
}
if (180 < valor 1 < 360)
{
    // aliquota 7,3%
    // desconto = 5940
}
if (360 < valor 1 < 720)
{
    // aliquota 9,5%
    // desconto = 13860
}
if (720 < valor 1 < 1800)
{
    // aliquota 10,7%
    // desconto = 22500
}
if (1800 valor 1 < 3600)
{
    // aliquota 14,3%
    // desconto = 87300
}
if (3600 < valor 1 < 4800)
{
    // aliquota 19%
    // desconto = 378000
}*/