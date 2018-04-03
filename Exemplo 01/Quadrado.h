#include <c2d2/chien2d2.h>
#include <c2d2/chienaudio2.h>
#include <c2d2/chien2d2primitivas.h>
#include <iostream>

using namespace std;

class Quadrado
{
public:
	int m_x, m_y;
	int m_w, m_h;
	int m_R, m_G, m_B;
	bool m_ativo;

	void DesenhaQuadrado()
	{
		C2D2P_RetanguloPintado(m_x, m_y, m_x + m_w, m_y + m_h, m_R, m_G, m_B);
		if (m_ativo==true)
			C2D2P_Retangulo(m_x, m_y, m_x + m_w, m_y + m_h, 0, 0, 0);
	}
	void Desenhoativo()
	{
		C2D2P_Retangulo(m_x, m_y, m_x + m_w, m_y + m_h, 0, 0, 0);
	}

	void Checarposiçao(int p_x, int p_y, int p_x2, int p_y2)
	{
		if (p_x > p_x2)
		{
			int a = p_x2;
			p_x2 = p_x;
			p_x = a;
		}
		if (p_y > p_y2)
		{
			int b = p_y2;
			p_y2 = p_y;
			p_y = b;
		}
		if (p_x <= m_x && p_x2>m_x + m_w)
		{
			if (p_y <= m_y && p_y2 > m_y + m_h)
				m_ativo = true;		
			else m_ativo = false;
		}
		else
			m_ativo = false;
	}

	void DesenhaQuadradopos(int p_x, int p_y)
	{
		if (m_ativo == true)
		{
			C2D2P_RetanguloPintado(p_x, p_y, p_x + m_w, p_y + m_h, m_R, m_G, m_B);
		}		
	}

	Quadrado(int p_x, int p_y, int p_w, int p_h, int p_R, int p_G, int p_B,bool p_ativo)
	{
		m_x = p_x;
		m_y = p_y;
		m_w = p_w;
		m_h = p_h;
		m_R = p_R;
		m_G = p_G;
		m_B = p_B;
		m_ativo = p_ativo;
	}
	Quadrado()
	{

	}

};