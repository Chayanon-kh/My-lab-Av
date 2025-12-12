#include <stdio.h>
void reverse( char str1[], char str2[] )
{
    int i, j = 0 ;
    while( str1[j] != '\0' )
    {
        j++ ;
    }
    j-- ;
    for( i = 0 ; i <= j ; i++ )
    {
        str2[i] = str1[j - i] ;
    }
    str2[i] = '\0' ;
}
int main() { 
char text[ 50 ];
char out[ 50 ] ;
scanf("%[^\n]" ,text) ;  
reverse( text, out ) ;
printf( "Reversed string: %s\n", out ) ;
return 0 ;
}