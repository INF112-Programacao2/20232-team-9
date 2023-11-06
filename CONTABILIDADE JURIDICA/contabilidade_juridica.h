#include "cadastro.h"
class ContabilidadeJuridica : public Cadastro{
	private:
		double _caixa[12];
		double _patrimonio;
		int _modelo;
	public:
		

		void set_caixa(double caixa[12]);
		void set_patrimonio(double patrimonio);
		void set_modelo(int modelo);

		double* get_caixa();
		double get_patrimonio();
		int get_modelo();
}