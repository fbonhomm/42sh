/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:33:41 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/24 18:04:15 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_ERROR_H
# define SH1_ERROR_H

# define EALLOC "Out of memory."
# define EFOUND "Command not found."
# define EACCESS "Unable to read or search a component of the path."
# define ESYN "Syntax error."
# define EARGS "Too many arguments."
# define EARG "Too few arguments."
# define ELPATH "Path buffer too long."
# define EPERMS "Permission denied."
# define EDIR "Not a directory."
# define EMANYF "Too many files are currenctly open."
# define EMANYP "Too many process are currenctly open."
# define ENONEX "No such file or directory."
# define ENOPATH "No path specified"
# define EDIRPRES "The directory was suppressed."
# define EPATHL "Path too long."
# define ENAMEL "Name too long."
# define ELYNK "Too many symbolik link."
# define ENVH "HOME not set."
# define ENVO "OLDPWD not set."
# define ENTERM "TERM not set."
# define ESIGN "Invalid signal."
# define EFFAULT "Bad adress."
# define ECREAT "File cant be created."
# define EOPEN "File cant be opened."
# define EREAD "File cant be read."
# define EWRITE "File cant be writed."
# define ECLOSE "File cant be closed."
# define EBOPEN "Bad file descriptor."
# define ESIGNER "A signal was interrupted the currenctly process."
# define EPPIPE "Broken pipe."
# define EPROCESS "Cant create a new process."
# define ETERM "Cant find terminal definition."
# define EEXECVE "Cant be executed."
# define EEINTR "Interrupted by a signal."
# define ESIGINT "Interrupted by SIGINT."
# define ESIGQUIT "Interrupted by SIGQUIT."
# define ESIGWINCH "Interrupted by SIGWINCH."
# define EUNKNOW "An error occured."
# define ETERMERR "Bad terminal capacities."
# define EGETCAP "Can't get terminal capacities."
# define ESETCAP "Can't set terminal capacities."
# define USENV "usage: env [-i] [name=value ...] [utility [argument ...]]"
# define USCD "usage: cd [-L|-P] [dir]"
# define PEICS "42sh: Unmatched \"\n42sh: parse error in command substitution"
# define PEICS2 "42sh: Unmatched \'\n42sh: parse error in command substitution"
# define SREGG "Not a regular file."
# define SDIRR "Not a directory."
# define SLNKK "Not a symbolik link."
# define SCHRR "Not chr file."
# define SFIFOO "Not fifo file."
# define SBLOCKK "Not bllock file."
# define SSOCKET "Not socket file."
# define ECHILDS "Too many child, stop that dude !"
# define SIGCTRL "we4fwefwef"
#endif
