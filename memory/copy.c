#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   char *s = get_string("s: ");
   char *t = malloc(strlen(s) + 1);

    if(t == NULL)
    {
        return 1;
    }

    for(int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    strlcpy(t,s);


    if(strlen(t) > 0)
        {
            t[0] = toupper(t[0]);
        }

   printf("s: %s\n", s);
   printf("t: %s\n", t);

   free(t);
}
