%
%
% Movimento de Projetil Sob Arrasto Aerodinâmico Quadrático
%
% Aula de 09/03/2016
%
% Equações Governantes : m d([v_i v_j]') / dt = -m [0 g_j] - Ca [v_i v_j]' [v_i v_j] 
%
% Solução Via Método de Euler / Diferenças Difinitas
% 			  
%

clear
clc

format long ;

function wx = fx(Ca, vy, vx, m, mi)
	wx = - (1./ m) * Ca * ( sqrt(vx*vx + vy*vy) * vx) - mi * vx ;
endfunction

function wy = fy(Ca, vy, vx, g, m, mi)
	wy = -g - (1./ m) * Ca * ( sqrt(vx*vx + vy*vy) * vy)  - mi * vy;
endfunction

function zx = gx(vx)
	zx = vx ;
endfunction

function zy = gy(vy)
	zy = vy ;
endfunction


% Dados - Caso 1
m     = 0.010 ;
Ca    = 0.00010 ;
mi    = 18.68e-6 ;
g      = 9.80 ;

% Iniciando Integração --- Condições e Parâmetros Iniciais


h   = 0.001 ;
t0  = 0 ;
x0  = 0 ;
y0  = 0.3 ;
V0    = 100.0 ;
tetha = 3.14159 * 30.00 / 180.0 ;
vx0 = V0 * cos(tetha) ;
vy0 = V0 * sin(tetha) ;

i   = 1;

 t  = t0 ;
 x  = x0 ;
 y  = y0 ;
 vx = vx0 ;
 vy = vy0 ;

while ( y > 0.0001 )



 	k11  = h * fx( Ca, vy, vx, m, mi ) ;
 	k12  = h * fy( Ca, vy, vx, g, m, mi ) ;
 	k13  = h * gx( vx ) ;
 	k14  = h * gy( vy ) ;

	t = t + 0.5 * h ;

 	k21  = h * fx( Ca, vy + 0.5 * k12, vx + 0.5 * k11, m, mi ) ;
 	k22  = h * fy( Ca, vy + 0.5 * k12, vx + 0.5 * k11, g, m, mi ) ;
 	k23  = h * gx( vx + 0.5 * k11 ) ;
 	k24  = h * gy( vy + 0.5 * k12 ) ;


 	k31  = h * fx( Ca, vy + 0.5 * k22, vx + 0.5 * k21, m, mi ) ;
 	k32  = h * fy( Ca, vy + 0.5 * k22, vx + 0.5 * k21, g, m, mi ) ;
 	k33  = h * gx( vx + 0.5 * k21 ) ;
 	k34  = h * gy( vy + 0.5 * k22 ) ;

	t = t + 0.5 * h ;

 	k41  = h * fx( Ca, vy + k32, vx + k31, m, mi ) ;
 	k42  = h * fy( Ca, vy + k32, vx + k31, g, m, mi ) ;
 	k43  = h * gx( vx + k31 ) ;
 	k44  = h * gy( vy + k32 ) ;


 	vx = vx + (1.0/6.0) * ( 1.0 * k11 + 2.0 * k21 + 2.0 * k31 + 1.0 * k41 ) ;
 	vy = vy + (1.0/6.0) * ( 1.0 * k12 + 2.0 * k22 + 2.0 * k32 + 1.0 * k42 ) ;
 	x  =  x + (1.0/6.0) * ( 1.0 * k13 + 2.0 * k23 + 2.0 * k33 + 1.0 * k43 ) ;
 	y  =  y + (1.0/6.0) * ( 1.0 * k14 + 2.0 * k24 + 2.0 * k34 + 1.0 * k44 ) ;    
  

 	i = i + 1 ;
 	tempo(i)  = t ;
 	posicx(i) = x ;
 	posicy(i) = y ;
%%

endwhile


% Saidas
disp(" ========================================================= ")
disp(" Movimento de Projetil Sob Arrasto Aerodinamico Quadratico ")
disp(" ========================================================= ")
disp(" Dados : ")
disp(" ======= ")
disp(" Massa : "), disp(m)
disp(" Aceleração da Gravidade : "), disp(g)
disp(" Coef. de Amortecimento : "), disp(Ca)
disp(" Condicoes Iniciais : ")
disp(" Velocidade Inicial : "), disp(V0)
disp(" Angulo de Disparo [graus] : "), disp(180 * tetha / pi) ;
disp(" =========================== ")
disp(" Saida : ")
disp(" ======= ")
disp(" Alcance : "), disp(x);

% Plotando
figure(1);
plot ( posicx, posicy, '*');