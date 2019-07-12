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


h   = 0.01 ;
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

    a_(1,1)=0;
    a_(2,1)=1/5;
    a_(3,1)=3/40; a_(3,2)=9/40;
    a_(4,1)=44/45; a_(4,2)=-56/15; a_(4,3)=32/9;
    a_(5,1)=19372/6561; a_(5,2)=-25360/2187; a_(5,3)=64448/6561; a_(5,4)=-212/729;
    a_(6,1)=9017/3168; a_(6,2)=-355/33; a_(6,3)=46732/5247; a_(6,4)=49/176; a_(6,5)=-5103/18656;
    a_(7,1)=35/384; a_(7,2)=0; a_(7,3)=500/1113; a_(7,4)=125/192; a_(7,5)=-2187/6784; a_(7,6)=11/84;
    % 4th order b-coefficients
    b4_(1,1)=5179/57600; b4_(2,1)=0; b4_(3,1)=7571/16695; b4_(4,1)=393/640; b4_(5,1)=-92097/339200; b4_(6,1)=187/2100; b4_(7,1)=1/40;
    % 5th order b-coefficients
    b5_(1,1)=35/384; b5_(2,1)=0; b5_(3,1)=500/1113; b5_(4,1)=125/192; b5_(5,1)=-2187/6784; b5_(6,1)=11/84; b5_(7,1)=0;
    for i=1:7,
     c_(i)=sum(a_(i,:));
    endfor

	k1_ = zeros(1,7);
	k2_ = zeros(1,7);
	k3_ = zeros(1,7);
	k4_ = zeros(1,7);

 	k1_(1)  = h * fx( Ca, vy, vx, m, mi ) ;
 	k2_(1)  = h * fy( Ca, vy, vx, g, m, mi ) ;
 	k3_(1)  = h * gx( vx ) ;
 	k4_(1)  = h * gy( vy ) ;

while ( y > 0.0001 )

    for j = 1:6,
    	k1_(j+1) = fx( Ca, vy + h*k2_(1:j)*a_(j+1,1:j)', vx + h*k1_(1:j)*a_(j+1,1:j)', m, mi ) ;
        k2_(j+1) = fy( Ca, vy + h*k2_(1:j)*a_(j+1,1:j)', vx + h*k1_(1:j)*a_(j+1,1:j)', g, m, mi ) ;
        k3_(j+1) = gx( vx + h*k1_(1:j)*a_(j+1,1:j)') ;
		k4_(j+1) = gy( vy + h*k2_(1:j)*a_(j+1,1:j)') ;                                    
    endfor

 	%vx = vx + h * (k1_ * b4_); 
 	%vy = vy + h * (k2_ * b4_); 
 	%x  =  x + h * (k3_ * b4_);
 	%y  =  y + h * (k4_ * b4_);

 	vx = vx + h * (k1_ * b5_); 
 	vy = vy + h * (k2_ * b5_); 
 	x  =  x + h * (k3_ * b5_);
 	y  =  y + h * (k4_ * b5_);  

 	i = i + 1 ;
 	t = t + h ;
 	tempo(i)  = t ;
 	posicx(i) = x ;
 	posicy(i) = y ;


 	k1_(1)  = k1_(7) ;
 	k2_(1)  = k2_(7) ; 
 	k3_(1)  = k3_(7) ;
 	k4_(1)  = k4_(7) ;

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

