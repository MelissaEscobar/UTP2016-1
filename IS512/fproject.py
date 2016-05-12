#!/usr/bin/python
# -*- coding: utf-8 -*-
#Project Details: This file is part of the final project of statistics
#Team members : Eliana Osorio, Sebastian Idarraga, Hector F. Jimenez
#File Details: Contains Colors, And Core functions
# url: github.com/heticor915/UTP2016-1/IS512Statistics
#   License Details:
#    Copyright (C) 2016  Hector F. Jimenez S.
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; Applies version 2 of the License.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
import core as core
import numpy as np
import scipy.stats as st
import matplotlib.pyplot as plt

"""
NOTA:Comentarios seran en ingles/Español.
Se debe usar scipy y modulo stats ya que viene con numerosas distribuciones de
probabilidad.

Todas las distribuciones continuas estan definidas en funcion de dos
parametros :
    -loc:: Es la media, centro de distribucion.
    -scale:: Es la desviacion tipica Sigma.

"""
version="1.0"
core.banner();                                          #Print the banner
print("%s[+]Ingrese Xmin\n%s")%(core.red,core.reset)
xmin=raw_input()
print("%s[+]Ingrese Xmax\n%s")%(core.green,core.reset)
xmax=raw_input()
print("%s[+]Ingrese el Valor de la Media\n%s")%(core.green,core.reset)
xbarra=raw_input()
print("%s[+]Ingrese el Valor de la Desviacion\n%s")%(core.green,core.reset)
sigma=raw_input()
z=(int(xmin)-int(xbarra))/int(sigma);                              #Calculate the proper Z for both ranges.
z2=(int(xmax)-int(xbarra))/int(sigma);
dsnormal=st.norm()                                  #Crea Objeto de Dist.Normal Estandar.
print("%s[+]Evaluando la Funcion de Distribucion en Z1=%d\n%s")%(core.green,z,core.reset)
dsnormal.cdf(z)                                     #Evaluamos la funcion de Distribucion en z1,z2
print("%s[+]Evaluando la Funcion de Distribucion en Z2=%d\n%s")%(core.green,z,core.reset)
dsnormal.cdf(z2)
print("%s[+]Generando la Densidad de Probabilidad entre 0.0 y 1.0\n%s")%(core.green,core.reset)
x=np.linspace(0.0,1.0)                              #Genera un array de datos entre 0-1.0
dsnormal.pdf(x)

"""Tambien hay una manera sencilla de hallar la densidad entre dos rangos.asi :
"""
st.norm.cdf(z)                              #Esto era lo que se pedia.
st.norm.pdf(x, -1.0, np.sqrt(sigma))        #Esto era lo que se pedia entregar.

#Eejmplo para graficar
x2=np.linspace(0.0, 1.0 )
plt.plot(x2,dsnormal.pdf(x2,-1.0, np.sqrt(0.5)) )
plt.show()
