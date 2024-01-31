/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:08:45 by mvpee             #+#    #+#             */
/*   Updated: 2024/01/31 15:42:33 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0, j = 0, k = 0;
    int *newArrays = malloc(sizeof(int) * (nums1Size + nums2Size));
    double median;

    while(k < nums1Size + nums2Size)
    {
        if (i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j]))
            newArrays[k] = nums1[i++];
        else
            newArrays[k] = nums2[j++];
        k++;
    }
    if ((nums1Size + nums2Size) % 2 == 0)
        median = (double)(newArrays[(nums1Size + nums2Size) / 2] + newArrays[((nums1Size + nums2Size) / 2) - 1]) /2;
    else
        median = (double)newArrays[(nums1Size + nums2Size) / 2];
    free(newArrays);
    return (median);
}

int main(void)
{
    int arrays1[] = {1, 3};
    int arrays2[] = {2, 7};
    int size1 = sizeof(arrays1) / sizeof(int);
    int size2 = sizeof(arrays2) / sizeof(int);

    double result = findMedianSortedArrays(arrays1, size1, arrays2, size2);
    printf("result: %f\n", result);
}