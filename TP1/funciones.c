
float funcionSuma(float x, float y)
{
    float suma;
    suma = x+y;
    return suma;
}
float funcionResta(float x, float y)
{
    float resta;
    resta = x-y;
    return resta;
}
float funcionDivision(float x, float y)
{
    float division;
    division=x/y;
    return division;
}
float funcionMultiplicacion(float x, float y)
{
    float producto;
    producto = x*y;
    return producto;
}
int funcionFactorial (float valor)
{
    int factorial;
    if(valor == 0)
    {
        return 1;
    }
    factorial= (int)valor*funcionFactorial((int)valor-1);
    return factorial;

}
