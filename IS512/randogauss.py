import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import core as core 
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

core.banner()
# example data
mu = input("[*] Ingrese la Media")
sigma = input("[*] Ingrese la Desviacion Estandar") 
print("Generando set de valores Aleatorios para x..")
x = mu + sigma * np.random.randn(10000)	#Aseguraos la inclusion de los mu, sigma 
print(x)
num_bins = 50
# datos para graficar el histograma.
n, bins, patches = plt.hist(x, num_bins, normed=1, facecolor='green', alpha=0.5)
# para agregar la mejor linea
y = mlab.normpdf(bins, mu, sigma)	#Calculo de los z
plt.plot(bins, y, 'r--')
plt.xlabel('X')
plt.ylabel('Y: Probabilidad')
plt.title(r'Distribucion Normal:  $\mu=$ %s , $\sigma=$ %s' %(str(mu),str(sigma)))
# Espaciado para las mejores Curvas. 
plt.subplots_adjust(left=0.15)
plt.show()
