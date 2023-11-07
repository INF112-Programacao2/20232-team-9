#include "cadastro.h"
#include <bits/stdc++.h>
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
	private:
		double _caixa[12];
		int _estoque;
		double _contasReceber;
		int _realizavelLongoPrazo;
		int _realizavelCurtoPrazo;
		double _emprestimos;
		double _contasPagar;

	public:
		//SET
		
		//ATIVO CIRCULANTE
		virtual void set_caixa() = 0;
		void set_estoque();
		virtual void set_contasReceber() = 0;

		//ATIVO NÃO CIRCULANTE
		virtual void set_realizavelLongoPrazo() = 0;
		
		//PASSIVO CIRCULANTE 
		virtual void set_realizavelCurtoPrazo() = 0;

		//PASSIVO NÃO CIRCULANTE
		virtual void set_emprestimos() = 0;
		virtual void set_contasPagar() = 0;

		//GET

		//ATIVO CIRCULANTE
		virtual double get_caixa() = 0;
		int get_estoque();
		virtual double get_contasReceber() = 0;

		//ATIVO NÃO CIRCULANTE
		virtual int get_realizavelLongoPrazo() = 0;

		//PASSIVO CIRCULANTE
		virtual int get_realizavelCurtoPrazo() = 0;

		//PASSIVO NÃO CIRCULANTE
		virtual double get_emprestimos() = 0;
		virtual double get_contasPagar() = 0;
		 
};