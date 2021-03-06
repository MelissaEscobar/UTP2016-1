#!/usr/bin/env python
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
import os, sys, subprocess
import string
import random
import time
import numpy as np
import scipy.stats as st
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import core as core

# Location for logs, modules and storage
ActivityLog = ("Logs")

# Xterm Colors
reset = '\x1b[0m'    # reset all colors to white on black
bold = '\x1b[1m'     # enable bold text
uline = '\x1b[4m'    # enable underlined text
nobold = '\x1b[22m'  # disable bold text
nouline = '\x1b[24m' # disable underlined text
red = '\x1b[31m'     # red text
green = '\x1b[32m'   # green text
blue = '\x1b[34m'    # blue text
cyan = '\x1b[36m'    # cyan text
white = '\x1b[37m'   # white text (use reset unless it's only temporary)
warning = "%s[!]%s"  % (red, reset)
info = "%s[*]%s" 	 % (green, reset)
version="1.0"				#Version of this Statistics Software

global probabilidad

def signalHandler(signal, frame):
    warning("Ctrl-C Para cerrar !")
    logging.info("[!] Ctrl+C signal caught. Shutting down Intersect!")

def menu():
	print """Elija Opcion para usar Distribucion Normal Estandar:
	[>1] Grafica de DNT Aleatoria
	[>2] Tipificacion de Variable
	[>3]
    [>4] Obtener valores de X1,X2 dado un Z.
	[>5] Acerca de
	[>6] Quit
	"""

def usage():
	print("%s%s[!!]Las Entradas deben ser numericas entre [1-6]%s")%(bold,red,reset)
	print("%s%s[!!]Corre el Script de Nuevo, o verifica los requisitos%s")%(bold,red,reset)


def operative(x):			#This is pretty straight forward work
	if x==1:
		DntRandom()				#Done
	elif x==2:
		Xz()				#Done
	elif x==3:
		Params()					#Falta
	elif x==4:
		Zx()							#Z to x, Done x= mu + (z)*sigma
	elif x==5:
		acercade()				#Done
	elif x==6:
		quit()						#Exit

def DntRandom():
	print("%s%s[+]%sIngrese la Media y La Desviacion Estandar%s: %s")%(bold,green,nobold,bold,reset)
	mu = input("mu >:")
	sigma = input("sigma >: ")
	time.sleep(2)
	print("%s%s>:[Ok]%s%sGenerando set de valores Aleatorios para x..%s")%(bold,red,nobold,green,reset)
	x = mu + sigma * np.random.randn(10000)	#Aseguraos la inclusion de los mu, sigma
	print(x)
	num_bins = 50
	# datos para graficar el histograma.
	print("%s%s>:[Ok]%s%sGenerando Histograma de MatplotLib..%s")%(bold,red,nobold,green,reset)
	time.sleep(2)
	n, bins, patches = plt.hist(x, num_bins, normed=1, facecolor='green', alpha=0.5)
  # para agregar la mejor linea
	print("%s%s>:[Ok]%s%sCalculando las Probabilidades para Construir Campana..%s")%(bold,red,nobold,green,reset)
	time.sleep(2)
	y = mlab.normpdf(bins, mu, sigma)									#Calculo de los z
	print("%s%s>:[Ok]%s%sGraficando Datos%s")%(bold,red,nobold,green,reset)
	time.sleep(1.2)
	plt.plot(bins, y, 'r*')
	plt.xlabel('X')
	plt.ylabel('Y: Probabilidad')
	plt.title(r'Distribucion Normal:  $\mu=$ %s , $\sigma=$ %s' %(str(mu),str(sigma)))
	# Espaciado para las mejores Curvas.
	plt.subplots_adjust(left=0.15)
	plt.show()


def Xz():
    print("%s%s[+]%sTipificando La Variable%s: %s")%(bold,green,nobold,bold,reset)
    print("%s%s[+]%sIngrese El valor Promedio%s: %s")%(bold,green,nobold,bold,reset)
    mu=input("mu >:")
    sigma=input("sigma >: ")
    x=input("x >: ")
    z=(x-mu)/1
    probabilidad=st.norm.cdf(z)
    print("Busqueda de  Z%d en Tabla es::: %s%s%s")%(z,bold,green,reset)
    print("La Probabilidad hallada en la Tabla es:%s%s%f%s")%(bold,green,probabilidad,reset)
    densidad=st.norm.pdf(probabilidad)
    print("La Densidad de Probabilidad es= %s%s%f%s")%(bold,green,densidad,reset)

def Zx():
	#funcion que dada una grafica representada por medio de una media(mu) y un desviacion tipica(sigma), permite saber entre que valores se encuentra un porcentaje de datos dado
	mu = input("mu >:")
	sigma = input("sigma >: ")
	percent=input("porcentaje >: ")
	Aux=percent/2
	Z1=0.5 + Aux
	Z2=0.5 - Aux
	probZ1=st.norm.ppf(Z1)
	probZ2=st.norm.ppf(Z2)
	limitInferior=mu+(probZ1*sigma)
	limitSuperior=mu+(probZ2*sigma)
	print 'El '
	print (percent) *100
	print '% de los datos se encuentran entre'
	print limitInferior
	print ' y '
	print limitSuperior

def Params():
		print("Not implemented yet.")


def acercade():
		subprocess.call(['clear'],shell=False)#clean term
		print"""%s%s
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		@@@@@@@     @@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@
		@@@@@@#  ;@@@@@@@@@@@@@@@@@@@@@@@@+   @@@@@@@@@
		@@@@@@. ;@@@@@@@@@#      ,@ ,@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@@,  ,##,    @@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@#  @@@@@@  .@@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@  @@@@@@;   @@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@ '@@@@@# ;' #@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@: @@@@@@ .@@ :@@@@@@@  @@@@@@@@@
		@@@@@@+ @@@@@@@` @@@@@ `@@@ `@@@@@@@`  @@@@@@@
		@@@    @@@@@@@@  @@@@  @@@@  @@@@@@@@.   @@@@@@
		@@@    ;@@@@@@@. @@@  @@@@@ .@@@@@@@@    @@@@@@
		@@@@@@  @@@@@@@; @@  @@@@@@ '@@@@@@@  '@@@@@@@@
		@@@@@@  @@@@@@@@ .  @@@@@@` @@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@   @@@@@@@  @@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@;  #@@@@@  @@@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@@ ,        @@@@@@@@@@  @@@@@@@@@
		@@@@@@  @@@@@@@ `@@`    :@@@@@@@@@@@  @@@@@@@@@
		@@@@@@. ;@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@
		@@@@@@#  ;@@@@@@@@@@@@@@@@@@@@@@@@+   @@@@@@@@@
		@@@@@@@`    @@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@
		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	%s		Hector F. Jimenez Saldarriaga
				Eliana Osorio
			Juan Esteban Idarraga
		Software Estadistica: Distribucion Normal T.
		Version 1.0%s
									"""% (white,bold,white,reset)

def quit():
		sys.exit();


# Random Banner
def banner():
    target = random.randrange(1,6)
    if target == 1:
        print """%s%s
       #######   #####
       ##     # #     #   ##   #    #  ####   ####
       ##     # #        #  #  #    # #      #
       ##     # #  #### #    # #    #  ####   ####
       ##     # #     # ###### #    #      #      #
       ######## #     # #    # #    # #    # #    #
       #######   #####  #    #  ####   ####   ####
            feedback:hfjimenez@utp.edu.co
                     lielosorio@utp.edu.co
                     idarrraga@utp.edu.co
                     V%s
		%sUniversidad Tecnologica de Pereira, ISC
												%s
        """ % (bold, blue, version, white,reset)

    elif target == 2:
        print """%s%s
        d8888b.  d888b   .d8b.  db    db .d8888. .d8888.
        88  `8D 88' Y8b d8' `8b 88    88 88'  YP 88'  YP
        88   88 88      88ooo88 88    88 `8bo.   `8bo.
        88   88 88  ooo 88~~~88 88    88   `Y8b.   `Y8b.
        88  .8D 88. ~8~ 88   88 88b  d88 db   8D db   8D
        Y8888D'  Y888P  YP   YP ~Y8888P' `8888Y' `8888Y'
            feedback:hfjimenez@utp.edu.co
                     lielosorio@utp.edu.co
                     idarrraga@utp.edu.co
                      V%s
        %sUniversidad Tecnologica de Pereira, ISC %s
        """ % (bold, cyan,version, white, reset)

    elif target == 3:
        print """%s%s
        8####8 8####8
        8    8 8    " eeeee e   e eeeee eeeee
        8e   8 8e     8   8 8   8 8   " 8   "
        88   8 88  ee 8eee8 8e  8 8eeee 8eeee
        88   8 88   8 88  8 88  8    88    88
        88eee8 88eee8 88  8 88ee8 8ee88 8ee88
            feedback:hfjimenez@utp.edu.co
                     lielosorio@utp.edu.co
                     idarrraga@utp.edu.co
                     V%s
         %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, white, version,white, reset)
    elif target == 4:
			print """%s%s
        8""""8 8""""8
        8    8 8    " eeeee e   e eeeee eeeee
        8e   8 8e     8   8 8   8 8   " 8   "
        88   8 88  ee 8eee8 8e  8 8eeee 8eeee
        88   8 88   8 88  8 88  8    88    88
        88eee8 88eee8 88  8 88ee8 8ee88 8ee88
         feedback:hfjimenez@utp.edu.co
                  lielosorio@utp.edu.co
                  idarrraga@utp.edu.co

          V%s
        %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, green,version, white, reset)
    elif target == 5:
        print """%s%s
        @@@@@@@   @@@@@@@   @@@@@@  @@@  @@@  @@@@@@  @@@@@@
        @@!  @@@ !@@       @@!  @@@ @@!  @@@ !@@     !@@
        @!@  !@! !@! @!@!@ @!@!@!@! @!@  !@!  !@@!!   !@@!!
        !!:  !!! :!!   !!: !!:  !!! !!:  !!!     !:!     !:!
        :: :  :   :: :: :   :   : :  :.:: :  ::.: :  ::.: :
         feedback:hfjimenez@utp.edu.co
                  lielosorio@utp.edu.co
                  idarrraga@utp.edu.co
                  %s
        %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, red,version,white, reset)

    elif target == 6:
				print """%s%s
       *******     ********
			/**////**   **//////**
			/**    /** **      //   ******   **   **  ******  ******
			/**    /**/**          //////** /**  /** **////  **////
			/**    /**/**    *****  ******* /**  /**//***** //*****
			/**    ** //**  ////** **////** /**  /** /////** /////**
			/*******   //******** //********//****** ******  ******
			///////     ////////   ////////  ////// //////  //////
         feedback:hfjimenez@utp.edu.co
                  lielosorio@utp.edu.co
                  idarrraga@utp.edu.co
                  %s
        %sUniversidad Tecnologica de Pereira, ISC%s
""" % (bold, red,version,white, reset)
