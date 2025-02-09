/* Figura 8.3: fig08_03.c
   Uso de las funciones islower, isupper, tolower, toupper */
#include <stdio.h>
#include <ctype.h>
int main()
{
    printf( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n","De acuerdo con islower:",islower( 'p' ) ? "p es una " : "p no es una ","letra minuscula",islower( 'P' ) ? "P es una " : "P no es una ","letra minuscula",islower( '5' ) ? "5 es una " : "5 no es una ","letra minuscula",islower( '!' ) ? "! es una " : "! no es una ","letra minuscula" );
    printf( "%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
            "De acuerdo con isupper:",
            isupper( 'D' ) ? "D es una " : "D no es una ",
            "letra mayuscula",
            isupper( 'd' ) ? "d es una " : "d no es una ",
            "letra mayuscula",
            isupper( '8' ) ? "8 es una " : "8 no es una ",
            "letra mayuscula",
            isupper( '$' ) ? "$ es una " : "$ no es una ",
            "letra mayuscula" );
    printf( "%s%c\n%s%c\n%s%c\n%s%c\n","u convertida a mayuscula es ", toupper( 'u' ),
            "7 convertida a mayuscula es ", toupper( '7' ),
            "$ convertida a mayuscula es ", toupper( '$' ),
            "L convertida a minuscula es ", tolower( 'L' ) );
    return 0; /* indica terminación exitosa */
} /* fin de main */
