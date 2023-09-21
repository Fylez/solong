/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:57:01 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:43:20 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
	{
		character = character - 32;
	}
	return (character);
}
/*int main(void)
{
  printf("%d", ft_strupcase("JFIEOWJFO"));
}*/