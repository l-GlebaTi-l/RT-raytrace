#include "vectors.h"

struct XYZ {
    double x;
    double y;
    double z;
};

XYZ vf(XYZ A, std::ifstream& file) // ВВОД ВЕКТОРА ИЗ ФАЙЛА
{
    file >> A.x;
    file >> A.y;
    file >> A.z;
    return A;
}
XYZ vector_return_tochky(XYZ AB, XYZ A){ // КОНЕЧНАЯ ТОЧКА ВЕКТОРА AB В ПРОСТРАНСТВЕ
    XYZ B;
    B.x = A.x + AB.x;
    B.y = A.y + AB.y;
    B.z = A.z + AB.z;
    return B;
}
XYZ vector_YnC(XYZ A, double k){ // УМНОЖЕНИЕ НА СКАЛЯР
    A.x = A.x*k;
    A.y = A.y*k;
    A.z = A.z*k;
    return A;
}
XYZ vector_sum(XYZ A, XYZ B){ // СУММА ВЕКТОРОВ
    XYZ C;
    C.x = A.x + B.x;
    C.y = A.y + B.y;
    C.z = A.z + B.z;
    return C;
}
double vector_SP(XYZ A, XYZ B){ // СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ
    return A.x*B.x + A.y*B.y + A.z*B.z;
}
double vector_module(XYZ A){ // ДЛИНА ВЕКТОРА
    return SqrtInv(A.x*A.x + A.y*A.y + A.z*A.z);
}
XYZ ve(XYZ A) // ВВОД ВЕКТОРА
{
    std::cout << "Enter vector:" << std::endl;
    std::cin >> A.x >> A.y >> A.z;
    return A;
}
void vector_print(XYZ A) // ВЫВОД ВЕКТОРА
{
    std::cout << A.x << " ";
    std::cout << A.y << " ";
    std::cout << A.z << std::endl;
}
XYZ o_vector(XYZ A, XYZ B){ // НАХОЖДЕНИЕ ВЕКТОРА AB
    XYZ ab;
    ab.x = B.x - A.x;
    ab.y = B.y - A.y;
    ab.z = B.z - A.z;
    return ab;
}
XYZ vector_perp(XYZ a1, XYZ a2){ // ПЕРПЕНДИКУЛЯР К ВЕКТОРАМ a1 и a2    OX * OY = OZ
    XYZ p;
    p.x = a1.y*a2.z - a1.z*a2.y;
    p.y = a1.z*a2.x - a1.x*a2.z;
    p.z = a1.x*a2.y - a1.y*a2.x;
    return p;
}
XYZ vector_ration(XYZ A){ // НОРМАЛИЗАЦИЯ ВЕКТОРА
    double l;
    l = A.x*A.x + A.y*A.y + A.z*A.z;
    l = SqrtInvE(l);
    A.x = A.x*l;
    A.y = A.y*l;
    A.z = A.z*l;
    return A;
}
XYZ vector_normal(XYZ ab, XYZ ac){ // НОРМАЛЬ К ВЕКТОРАМ
    XYZ n;
    n = vector_perp(ab, ac);
    n = vector_ration(n);
    return n;
}
XYZ vector_sim(XYZ A){ // ИЗМЕНЕНИЕ ОРИЕНТАЦИИ ВЕКТОРА
    A.x = -A.x;
    A.y = -A.y;
    A.z = -A.z;
    return A;
}
double vector_ygol(XYZ AB, XYZ AC){
    double cosBAC;
    AB = vector_ration(AB);
    AC = vector_ration(AC);
    cosBAC = vector_SP(AB,AC);
    return cosBAC;
}


            ///             Быстрая и практичная функции
/**
float Q_rsqrt( float number )       /// Быстрая (в 4 раза быстрее sqrt, но точность ~0.0017 (1 = 1.0017)) 27 ms
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    y = 1/y;
	return y;
}
float Q_rsqrt2( float number )      /// Быстрее предыдущей, разницы в ответе нет (ЛУЧШЕ) 23 ms
{
	const float x2 = number * 0.5F;
	const float threehalfs = 1.5F;

	union {
		float f;
		uint32_t i;
	} conv = {number}; // member 'f' set to value of 'number'.
	conv.i  = 0x5f3759df - ( conv.i >> 1 );
	conv.f  *= ( threehalfs - ( x2 * conv.f * conv.f ) );
	conv.f = 1/conv.f;
	return conv.f;
}
**/

float SqrtInv (float x)             /// Практичная (точность sqrt, но быстрее в 2 раза) 41 ms
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    x = x*(1.5f - xhalf*x*x);
    x = x*(1.5f - xhalf*x*x);
    x=1/x;
    return x;
}
float SqrtInvE(float x)             /// Полная точность, 1/корень 28 ms
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    x = x*(1.5f - xhalf*x*x);
    x = x*(1.5f - xhalf*x*x);
    return x;
}
float Q_rsqrt2E( float number )     /// Очень практичная, 1/корень, быстрее в 2 раза корня, 15 ms
{
	const float x2 = number * 0.5F;
	const float threehalfs = 1.5F;

	union {
		float f;
		uint32_t i;
	} conv = {number}; // member 'f' set to value of 'number'.
	conv.i  = 0x5f3759df - ( conv.i >> 1 );
	conv.f  *= ( threehalfs - ( x2 * conv.f * conv.f ) );
	return conv.f;
}
