/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:10:20 by mvan-pee          #+#    #+#             */
/*   Updated: 2024/01/30 11:36:26 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;
    int *result;
    
    result = (int *)malloc(sizeof(int) * 2);
    i = 0;
    while(i < numsSize)
    {
        j = i + 1;
        while(j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return (result);
            }
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    int array[] = {2,7,11,15};
    int target = 9;
    int numSize = sizeof(array) / sizeof(int);
    int result_size;
    int *result;

    result = twoSum(array, numSize, 9, &result_size);
    if (!result)
        return (1);
    printf("%d %d\n", result[0], result[1]);
    free(result);
    return (0);
}