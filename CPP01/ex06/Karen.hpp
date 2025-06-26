/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:30:11 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:30:11 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen 
{
	public:
		enum LEVELS {DEBUG, INFO, WARNING, ERROR, LEVELS};
		void complain( std::string );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif /*KAREN_HPP*/
