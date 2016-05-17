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
import sys, subprocess

#if __name__=='__main__':
                   #Print the banner
while True:
	subprocess.call(['clear'],shell=False)#clean term 
	core.banner()													#Generate a Random banner
	core.menu()														#Dmenu...
	opcion=int(raw_input("[:::]> ")) 			#Casting the option entered by the user
	if((opcion>6) or (opcion<1) ):				#Validator...break the infinite while cicle 
		core.usage();												#Print proper usage
		raw_input();												#Wait for enter
		break
	core.operative(opcion)								#Do the homework :P 
	raw_input();													#Debug 
  
