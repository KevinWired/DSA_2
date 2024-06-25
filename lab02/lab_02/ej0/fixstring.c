#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

bool fstring_empty(fixstring s)
{
	return s[0]=='\0';
}

unsigned int fstring_length(fixstring s) 
{


	if(fstring_empty(s))
	{
		return 0;
	}
	else
	{
		unsigned int length = 0;
		
		while(s[length]!='\0' && length<FIXSTRING_MAX-1)
		{
			length = length + 1;
		}
		
		return length;
	} 

}

bool fstring_eq(fixstring s1, fixstring s2)
{
  bool flag = true;
  unsigned int lngt_1 = fstring_length(s1);
  unsigned int lngt_2 = fstring_length(s2);

  if (lngt_1 != lngt_2)
	{
	assert(lngt_1!=lngt_2);
	
	return false;
	}
	else
	{
	  for(unsigned int k = 0; k<lngt_1 && flag && s1[k] != '\0' && s1[k] != '\0'; k++)
		{
		  flag = flag && (s1[k] == s2[k]);
		}
	}
		
  return flag;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
  assert(!fstring_empty(s1) && !fstring_empty(s2));
  
  unsigned int size_s1 = fstring_length(s1);
  unsigned int size_s2 = fstring_length(s2);
  unsigned int i = 0;
  
  while (i < size_s1 && i < size_s2)
  {
    char x = s1[i];
    char y = s2[i];
    
    if (x < y)
      return true;
    else if (x > y)
      return false;
    
    i++;
  }
  return size_s1 <= size_s2;
}

