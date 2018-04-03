#include <c2d2/chien2d2.h>
#include <c2d2/chienaudio2.h>
#include <c2d2/chien2d2primitivas.h>
#include "Quadrado.h"
#include "Array.h"
#include "BubbleSorth.h"

int ComparaQuadrados(Quadrado p_1, Quadrado p_2)
{
	if (p_1.m_ativo)
	{
		if (p_2.m_ativo)
		{
			if (p_1.m_B > p_2.m_B)
			{
				return 1;
			}
			if (p_1.m_G > p_2.m_G)
			{
				if (p_1.m_B > p_2.m_B)
				{
					return 0;
				}
				if (p_2.m_B > p_1.m_B)
				{
					return 0;
				}
				else return 1;
			}
		}
		return 0;
	}
	if (p_2.m_ativo)
		return 1;
}

int main(int ac, char **av)
{
	
	C2D2_Inicia(1300, 700, C2D2_JANELA, C2D2_DESENHO_OPENGL, "Minha Janela Chien 2D");
	
	C2D2P_Inicia();

	C2D2_Botao *teclado;
	teclado = C2D2_PegaTeclas();
	C2D2_Mouse *mouse;
	mouse = C2D2_PegaMouse();

	C2D2_TrocaCorLimpezaTela(255, 255, 255);

	Quadrado quadrado1(200, 200, 50, 50, 0, 0, 255, false);
	Quadrado quadrado2(300, 100, 50, 50, 0, 255, 0, false);
	Quadrado quadrado3(435, 200, 50, 50, 255, 0, 0, false);
	Quadrado quadrado4(950, 250, 50, 50, 0, 255, 0, false);
	Quadrado quadrado5(900, 300, 50, 50, 0, 0, 255, false);
	Quadrado quadrado6(650, 450, 50, 50, 255, 0, 0, false);

	Array<Quadrado> quadrados(6);
	quadrados[0] = quadrado1;
	quadrados[1] = quadrado2;
	quadrados[2] = quadrado3;
	quadrados[3] = quadrado4;
	quadrados[4] = quadrado5;
	quadrados[5] = quadrado6;
	
	Array<Quadrado> quadradosS(6);
	quadradosS = quadrados;
	int x, y;

	

	while (true)
	{		
		if (teclado[C2D2_ESC].pressionado)
			exit(0);

		C2D2_LimpaTela();
		for (int i = 0; i < 6; i++)
		{
			quadrados[i].DesenhaQuadrado();
		}		

		C2D2P_RetanguloPintado(0, 550, 1300, 700, 0, 0, 0);
		
		int a = C2D2_CarregaFonte("imagem3.jpg", 16);

		C2D2_DesenhaTexto(a, 0, 0, "Formado R,G,B", C2D2_TEXTO_DIREITA);

		BublleSort<Quadrado>(quadradosS, ComparaQuadrados);

		for (int g = 0; g < 6; g++){
			quadradosS[g].DesenhaQuadradopos(25 + (50 * g)+(25*g), 600);
		}

		C2D2P_RetanguloPintado(mouse->x, mouse->y, mouse->x + 5, mouse->y + 5, 0, 0, 0);
		if (mouse->botoes->pressionado)
		{
			x = mouse->x;
			y = mouse->y;
		}		


		if (mouse->botoes->ativo)
		{				
			C2D2P_RetanguloPintadoAlfa(x, y, mouse->x, mouse->y, 0, 255, 0, 150);			
		}
		if (mouse->botoes->liberado)
		{
			for (int e = 0; e < 6; e++)
			{
				quadrados[e].Checarposiçao(x, y, mouse->x, mouse->y);
			}			
		}
		

		C2D2_Sincroniza(C2D2_FPS_PADRAO);		
	}
	return 0;
}