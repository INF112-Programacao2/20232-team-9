#include <iostream>
#include "cadastro.h"
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "estatisticos.h"
#include "prestacao_de_servico.h"
#include "comercio.h"


int main(){

    Cadastro c1 ("Hugo Costa", "HugoCia", "HCAvulk", "Coronel Fabriciano");

    c1.get_nomepessoa ();

    return 0;
}