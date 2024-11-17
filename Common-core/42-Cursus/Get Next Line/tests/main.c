/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:54:00 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/17 22:35:46 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

static void test_gnl(int file_descriptor, char const *current_file)
{
    char *current_line;
    int line_counter = 0;

    printf("Testing file %s\n", current_file);
    while (true)
    {
        current_line = get_next_line(file_descriptor);
        line_counter++;
        if (current_line == NULL)
            break;
        printf("LINE %d: '%s'\n", line_counter, current_line);
        free(current_line);
    }
    printf("---------------------------------------------------------------\n");
    close(file_descriptor);
}

int main(void)
{
    char const *current_file;
    int current_file_descriptor;

    current_file = "./tests/examples/test1";
    current_file_descriptor = open(current_file, O_RDONLY);
    if (current_file_descriptor < 0)
    {
        perror("Failed to open file");
        return (1);
    }
    test_gnl(current_file_descriptor, current_file);

    current_file = "./tests/examples/test2";
    current_file_descriptor = open(current_file, O_RDONLY);
    if (current_file_descriptor < 0)
    {
        perror("Failed to open file");
        return (1);
    }
    test_gnl(current_file_descriptor, current_file);

    current_file = "./tests/examples/test3";
    current_file_descriptor = open(current_file, O_RDONLY);
    if (current_file_descriptor < 0)
    {
        perror("Failed to open file");
        return (1);
    }
    test_gnl(current_file_descriptor, current_file);

	//current_file = "./tests/examples/big_line_no_nl";
    //current_file_descriptor = open(current_file, O_RDONLY);
    //if (current_file_descriptor < 0)
    //{
    //    perror("Failed to open file");
    //    return (1);
    //}
    //test_gnl(current_file_descriptor, current_file);

	//current_file = "./tests/examples/big_line_with_nl";
    //current_file_descriptor = open(current_file, O_RDONLY);
    //if (current_file_descriptor < 0)
    //{
    //    perror("Failed to open file");
    //    return (1);
    //}
    //test_gnl(current_file_descriptor, current_file);

	//current_file = "./tests/examples/42_no_nl";
    //current_file_descriptor = open(current_file, O_RDONLY);
    //if (current_file_descriptor < 0)
    //{
    //    perror("Failed to open file");
    //    return (1);
    //}
    //test_gnl(current_file_descriptor, current_file);

	//current_file = "./tests/examples/42_with_nl";
    //current_file_descriptor = open(current_file, O_RDONLY);
    //if (current_file_descriptor < 0)
    //{
    //    perror("Failed to open file");
    //    return (1);
    //}
    //test_gnl(current_file_descriptor, current_file);

    return (0);
}