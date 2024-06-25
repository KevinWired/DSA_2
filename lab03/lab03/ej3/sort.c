#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y)
{
    return x.rank <= y.rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) 
{
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int i, unsigned int j)
{
	player_t aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

static unsigned int partition(player_t a[], unsigned int lft, unsigned int rgt)
{

  unsigned int ppiv = lft;
  unsigned int i = lft+1u;
  unsigned int j = rgt;
	
	while(i<=j)
	{
		if(goes_before(a[i], a[ppiv]))
		{
			i = i+1u;
		}
		else if(goes_before(a[ppiv],a[j]))
		{
			j = j-1u;
		}
		else
		{
			swap(a,i,j);
			
			i = i+1u;
			
			j = j-1u;		
		}
	}
	
	swap(a,ppiv,j);
	
	ppiv = j;
	
	return ppiv;
}

static void quick_sort_rec(player_t a[], unsigned int lft, unsigned int rgt) 
{
 unsigned int ppiv;
 ppiv = partition(a, lft, rgt);
 if(ppiv > lft) 
 {
 	quick_sort_rec(a, lft, ppiv-1u);
 }
 if(ppiv < rgt)
 {
 	quick_sort_rec(a, ppiv+1u, rgt);
 }
}

static void quick_sort(player_t a[], unsigned int length) 
{
	quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

void sort(player_t a[], unsigned int length) {
    quick_sort(a, length);
}
