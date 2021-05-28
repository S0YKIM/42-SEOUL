#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
  int res = 0;
  va_list ap;
  int i;
  
  va_start(ap, count);
        
  for(i=0; i<count; i++)
    res += va_arg(ap, int);
  va_end(ap);
  return res;
}

int main()
{
  printf("%d\n", sum(10, 1,2,3,4,5,6,7,8,9,10));
  return (0);
}

// 출력 결과: 55
