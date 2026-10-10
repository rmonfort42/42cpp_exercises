/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:50:00 by rmonfort          #+#    #+#             */
/*   Updated: 2026/10/09 15:50:00 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

/*
** replaceAll(): devuelve una copia de 'content' con TODAS las apariciones de
** 's1' sustituidas por 's2'.
**
** No se puede usar std::string::replace (prohibido por el subject), asi que
** se construye la salida a mano:
**   - 'pos' apunta al inicio del trozo que aun no se ha copiado.
**   - 'find' busca 's1' a partir de 'pos'.
**   - Se copia con append() lo que hay ANTES del match, luego 's2', y se
**     salta el match avanzando 'pos' justo despues de 's1'.
**   - Al salir del bucle se copia el resto de la cadena (la cola sin match).
** Casos: si 's1' no aparece, el bucle no se ejecuta y se copia todo 'content'
** tal cual. 's1' nunca puede ser vacio (se comprueba en main), por lo que no
** hay bucle infinito.
*/
static std::string replaceAll(const std::string& content,
	const std::string& s1, const std::string& s2)
{
	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);
	return result;
}

int main(int argc, char **argv)
{
	/* Parseo de errores 1: numero de argumentos.
	** Se esperan 3 argumentos ademas del nombre del programa
	** (fichero, s1, s2), por eso argc debe valer exactamente 4.
	** Si no, se muestra el uso correcto y se sale con codigo 1. */
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	/* Parseo de errores 2: 's1' no puede estar vacio.
	** Con s1 == "" el replaceAll() se quedaria en un bucle infinito
	** (find siempre encuentra la cadena vacia en la misma posicion).
	** Por eso se rechaza y se sale con codigo 1. */
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}

	/* Apertura del fichero de entrada.
	** Parseo de errores 3: si el fichero no existe o no se puede leer,
	** is_open() es false -> mensaje de error y salida con codigo 1. */
	std::ifstream in(filename.c_str(), std::ios::binary);
	if (!in.is_open())
	{
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		return 1;
	}

	/* Se lee TODO el contenido de una vez con istreambuf_iterator.
	** Se abre en modo binario para copiar el fichero byte a byte, sin que la
	** libreria traduzca finales de linea, conservando el contenido EXACTO
	** (incluido si el original no termina en '\n'). */
	std::string content((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	in.close();

	std::string result = replaceAll(content, s1, s2);

	/* Creacion del fichero de salida <filename>.replace.
	** Parseo de errores 4: si no se puede crear (permisos, ruta...), is_open()
	** es false -> mensaje de error y salida con codigo 1. */
	std::string outName = filename + ".replace";
	std::ofstream out(outName.c_str(), std::ios::binary);
	if (!out.is_open())
	{
		std::cerr << "Error: cannot create output file: " << outName << std::endl;
		return 1;
	}

	/* Escritura del resultado y cierre explicito del flujo. */
	out << result;
	out.close();
	return 0;
}
