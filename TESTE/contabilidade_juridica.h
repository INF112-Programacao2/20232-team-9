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

class ContabilJuridica {
	private:
		std::vector<int> _caixa;
		std::vector<std::pair<std::string, double>> _contasPagar; //CÁCULO DRE
		std::vector<std::pair<std::string, double>> _contasReceber; //CÁLCULO DRE
		std::vector<std::pair<std::string, double>> _realizavelLongoPrazo; //CÁLCULO BALANCETE
		std::vector<std::pair<std::string, double>> _realizavelCurtoPrazo; 
		std::vector<std::pair<std::string, double>> _emprestimos;
		std::vector<int> _receitas;
		std::vector<int> _despesas;
		std::vector<int> _result_dre;
		double _receita_bruta;


	public:
		//SET
		
		//ATIVO CIRCULANTE
		void set_caixa(int qntelement);
		void set_contasReceber(int qntelement);

		//ATIVO NÃO CIRCULANTE
		void set_realizavelLongoPrazo(int qntelement);

		//PASSIVO CIRCULANTE
		void set_realizavelCurtoPrazo(int qntelement);

		//PASSIVO NÃO CIRCULANTE
		void set_emprestimos(int qntelement);
		void set_contasPagar(int qntelement);

		//GET

		//ATIVO CIRCULANTE
		double get_caixa();
		int get_estoque();
		double get_contasReceber();

		//ATIVO NÃO CIRCULANTE
		int get_realizavelLongoPrazo();

		//PASSIVO CIRCULANTE
		int get_realizavelCurtoPrazo();

		//PASSIVO NÃO CIRCULANTE
		double get_emprestimos();
		double get_contasPagar();

		//METODOS
		void _calculo_DRE();
		void _calculo_fluxo_caixa();
		void _resultado_balancete();
		void _calculo_aliquotas_localidade(PessoaJuridica &juridico);
		double get_receita_bruta();
		virtual void _calculo_aliquotas_anexos() = 0;
		virtual double get_result_simples_nacional() = 0;


		 
};