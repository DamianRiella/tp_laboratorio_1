#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"



/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    //fpurge(stdin); //UNIX
    scanf("%c",&auxiliar);
    return auxiliar;
}
/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}
/*****************************************************************/

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atoi(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxFloat;

    }


}
/*****************************************************/

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        clean_stdin();
        break;
    }

}

/**
 * \brief Detiene la ejecucion y muestra un mensaje
 * \param message Mensaje
 * \return -
 *
 */
void pause(char message[])
{
    getChar(message);
    clean_stdin();
}
/***************************************************************/

/***************************************************************/
/** \brief Verifica si el valor recibido es numerico.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es numerico y 0 si no lo es.
*
*/
int utn_esNumericoAvanzada (char cadena [])
{
    int i=0;
    int retorno = 0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9' )
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getIntAvanzada(int* pResultado)
{
    int retorno = 0;
    char buffer[64];

    if(pResultado!=NULL)
    {
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esNumericoAvanzada(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero ingresado, luego de validar el dato.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto. // OJO HAY QUE PONER EL & EN LA VARIABLE... ej &arrayEmployees[i].sector
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    int numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getIntAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}

/** \brief Verifica si el valor recibido es decimal.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es decimal y 0 si no lo es.
*
*/
int utn_esDecimalAvanzada(char cadena [])
{
    int i=0;
    int retorno = 0;
    int contadorPuntos=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] == '.')
            {
                contadorPuntos++;
            }

            if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.') && (contadorPuntos != 1))
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero decimal ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getFloatAvanzada(float* pResultado)
{
    int retorno = 0;
    char buffer[64];

    if(pResultado!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esDecimalAvanzada(buffer))
        {
            *pResultado = atof(buffer); // VER SI ATOF ESTA OK
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero con decimal ingresado, luego de validar el dato.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    float numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getFloatAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}

/** \brief Valida que la cadena de caracteres ingresada posea solo letras y espacios vacios.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_esStringAvanzada(char cadena [])
{
    int i=0;
    int retorno=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if ((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i]< 'A' || cadena[i]> 'Z')&& (cadena[i] != ' '))
            break;

            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena la cadena de caracteres ingresada y la devuelve.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getStringAvanzada(char cadena [])
{
    int retorno = 0;
    char buffer[64];

    if(cadena!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esStringAvanzada(buffer))
        {
            strcpy( cadena, buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Obtiene una cadena de caracteres y la valida. (solo letras y espacios vacios).
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
{
    int retorno;
    char texto [52];

        if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getStringAvanzada(texto))
                    break;

                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                strcpy(cadena, texto );
                retorno=1;
            }
        }
            return retorno;
}
