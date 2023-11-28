#include "pessoajuridica.h"
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

class ContabilJuridica : public PessoaJuridica{
	private:
		std::vector<int> _caixa;
		std::vector<std::pair<std::string, double>> _contasPagar; //CÁCULO DRE
		std::vector<std::pair<std::string, double>> _contasReceber; //CÁLCULO DRE
		std::vector<std::pair<std::string, double>> _realizavelLongoPrazo; //CÁLCULO BALANCETE
		std::vector<std::pair<std::string, double>> _realizavelCurtoPrazo; 
		std::vector<std::pair<std::string, double>> _emprestimos;
		std::vector<std::pair<std::string, double>> _contasPagar;
		std::vector<int> _receitas;
		std::vector<int> _despesas;
		std::vector<int> _result_dre;


	public:
		//SET
		
		//ATIVO CIRCULANTE
		virtual void set_caixa(int qntelement) = 0;
		virtual void set_contasReceber(int qntelement) = 0;

		//ATIVO NÃO CIRCULANTE
		virtual void set_realizavelLongoPrazo(int qntelement) = 0;

		//PASSIVO CIRCULANTE
		virtual void set_realizavelCurtoPrazo(int qntelement) = 0;

		//PASSIVO NÃO CIRCULANTE
		virtual void set_emprestimos(int qntelement) = 0;
		virtual void set_contasPagar(int qntelement) = 0;

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

		//METODOS
		void _calculo_DRE();
		void _calculo_fluxo_caixa();
		void _resultado_balancete();
		void _calculo_aliquotas();
		void _calculo_CNAE();

		 
};