#include "cadastro.h"
// tributação federal:
// tributação estadual:
// tributação por municipio:
// CNAE sob tipo de empresa (qual atuação no ramo)
// Razão social : nome da empresa
// apelido : nome fantasia
// NATUREZA JURIDICA (ja vem no cnpj)
// IPI (depende do ramo)
// Verificar se tem matriz, filial ou franquia
// dados basicos sobre a empresa
// PLANOS DE CONTAS PARA CADA MODELO DE NEGÓCIO
// PLANO DE CONTAS É O BALANÇO
// BALANÇO (feito após feito plano de contas, podendo ser mensal, trimestral, semestral ou anual)
// o balanço será feito com  vetores (para guardar datas) com double (dinheiro) e deve ser fechado (as contas devem bater)
//  a tributação é totalmente feita pelo CNAE
// LUCRO REAL, SIMPLES NACIONAL, MICROEMPRESA, ETC (formas de tributação)

//------------------------------------------------------------------------------------

//CLASSE INTERFACE PARA CONTABILIDADE JURIDICA

class ContabilJuridica : public Cadastro{

	public:
		//SET
		
		//ATIVO CIRCULANTE
		virtual void set_caixa() = 0;
		virtual void set_estoque() = 0;
		virtual void set_contasreceber() = 0;

		//ATIVO NÃO CIRCULANTE
		virtual void set_realizavellongoprazo() = 0;
		
		//PASSIVO CIRCULANTE 
		virtual void set_curtoprazo() = 0;

		//PASSIVO NÃO CIRCULANTE
		virtual void set_emprestimos() = 0;
		virtual void set_contaspagar() = 0;

		//GET

		//ATIVO CIRCULANTE
		virtual void get_caixa() = 0;
		virtual void get_estoque() = 0;
		virtual void get_contasreceber() = 0;

		//ATIVO NÃO CIRCULANTE
		virtual void get_realizavellongoprazo() = 0;

		//PASSIVO CIRCULANTE
		virtual void get_curtoprazo() = 0;

		//PASSIVO NÃO CIRCULANTE
		virtual void get_emprestimos() = 0;
		virtual void get_contaspagar() = 0;
		 
};