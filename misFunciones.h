/** \brief Funcion que suma dos numeros enteros
 *
 * \param x float primer numero de la operacion
 * \param y float segundo numero de la operacion
 * \return float Devuelve el resultado de la operacion
 *
 */
float suma(float x, float y)
{
    return x+y;
}
/** \brief Funcion que calcula la diferencia de dos numeros
 *
 * \param x float primer numero de la operacion
 * \param y float segundo numero de la operacion
 * \return float Devuelve el resultado de la operacion
 *
 */
float resta(float x, float y)
{
    return x-y;
}
/** \brief Funcion que calcula el producto de dos numeros
 *
 * \param x float primer numero de la operacion
 * \param y float segundo numero de la operacion
 * \return float Devuelve el resultado de la operacion
 *
 */
float producto(float x, float y)
{
    return x*y;
}
/** \brief Funcion que calcula el cociente entre dos numeros
 *
 * \param x float primer numero de la operacion, que actua como dividendo
 * \param y float segundo numero de la operacion, que actua como divisor
 * \return float Devuelve el resultado de la division
 *
 */
float division(float x, float y)
{
    return x/y;
}
/** \brief Funcion que calcula el factorial de un numero
 *
 * \param x float Es el numero al que se le calcula el factorial
 * \return int Devuelve el resultado de la operacion
 *
 */
int factorial(float x)
{
    int fact=1;
    int aux;
    aux=(int)x;
    for(int i=x; i>0; i--)
    {
        fact=fact*i;
    }
        int res= fact;
}
