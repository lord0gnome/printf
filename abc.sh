# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 14:38:19 by guiricha          #+#    #+#              #
#    Updated: 2016/02/13 16:18:09 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear

echo "COMPILING MAIN WITHOUT FLAGS"
gcc main.c ft_printf.c ft_small_functions.c ft_parse_and_store.c ft_very_small_functions.c ft_putll.c ft_length_funcs.c ft_print_hex.c ft_print_bin.c libft.a -w
echo "................................\n................................\n................................\n................................"
echo "RUNNING ./a.out WITH NO ARGS"
./a.out
