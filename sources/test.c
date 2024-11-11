#include <unistd.h>
#include <stdio.h>

int ft_is_char(char *str, char c, int k) 
{
    int i = 0;
    while (i < k) 
    {
        if (str[i] == c) 
        {
            return 1; 
        }
        i++;
    }
    return 0; 
}

int ft_is_char2(char *str, char c) 
{
    int i = 0;
    while (str[i]!='\0') 
    {
        if (str[i] == c) 
        {
            return 1; 
        }
        i++;
    }
    return 0; 
}



int main(int ac, char **av) 
{
    int i = 0;

    if (ac == 3)
    {
        while (av[1][i] != '\0')
        {
            if (ft_is_char2(av[2], av[1][i]) == 1 && ft_is_char(av[1],av[1][i],i) == 0)
            {
                write(1,&av[1][i],1);
            }
            i++;
        }
     }
    write(1, "\n", 1);
    return 0;
}