ElementType EvalPostfix(char *expr)
{
    double stk[1111], p1, p2;
    int len = strlen(expr), i, j, f = 0, top = -1;
    char *tmp;
    for (i = 0; expr[i]; i++)
        {
            if (!i)
                {
                    if (expr[0] == '-' && expr[1] == '\0')
                        return Infinity;
                    if (!isdigit(expr[0]) && expr[0] != '-')
                        f = 1;
                }
            else if (expr[i] != '.' && !isdigit(expr[i]))
                {
                    f = 1;
                }
        }
    expr[len] = ' ', expr[len + 1] = '\0';
    //  cout << f << endl;
    if (!f)
        return atof(expr);
    i = 0; // 11 -2 5.5 * +23 7 / -
    while (expr[i] != '\0')
        {
            if (expr[i] == ' ')
                {
                    expr[i++] = '\0';
                    tmp = expr;
                    expr += i;
                    i = 0;
                    if (!strchr("0123456789.+-*/", tmp[0]))
                        return Infinity;
                    if (strchr("*/+-", tmp[0]) && tmp[1] == '\0')
                        {
                            if (top - 2 < -1)
                                return Infinity;
                            p1 = stk[top--];
                            p2 = stk[top--];
                            if (tmp[0] == '+')
                                stk[++top] = p1 + p2;
                            else if (tmp[0] == '-')
                                stk[++top] = p2 - p1;
                            else if (tmp[0] == '*')
                                stk[++top] = p2 * p1;
                            else if (tmp[0] == '/')
                                {
                                    if (p1 == 0)
                                        return Infinity;
                                    stk[++top] = p2 / p1;
                                }
                        }
                    else
                        stk[++top] = atof(tmp);
                }
            else
                i++;
        }
    if (top - 1 == -1)
        return stk[0];
    return Infinity;
}