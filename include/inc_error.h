/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:46:03 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/05/25 17:22:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_ERROR_H
# define INC_ERROR_H

# define	MAX_ERROR	78

const char 		errlst[80][50] =
{
    "no error (operation succeeded)",
    "not owner",
    "no such file or directory",
    "no such process",
    "interrupted system call",
    "I/O error",
    "no such device or address",
    "argument list too long",
    "exec format error",
    "bad file number",
    "no children",
    "no more processes",
    "not enough memory",
    "permission denied",
    "bad address in system call argument",
    "block device required",
    "mount device busy",
    "file already exists",
    "cross-domain link",
    "no such device",
    "not a directory",
    "illegal operation on a directory",
    "invalid argument",
    "file table overflow",
    "too many open files",
    "inappropriate device for ioctl",
    "text file or pseudo-device busy",
    "file too large",
    "no space left in file system domain",
    "illegal seek",
    "read-only file system",
    "too many links",
    "broken pipe",
    "math argument out of range",
    "math result unrepresentable",
    "operation would block",
    "operation now in progress",
    "operation already in progress",
    "socket operation on non-socket",
    "destination address required",
    "message too long",
    "protocol wrong type for socket",
    "bad proocol option",
    "protocol not suppored",
    "socket type not supported",
    "operation not supported on socket",
    "protocol family not supported",
    "address family not supported by protocol family",
    "address already in use",
    "can't assign requested address",
    "network is down",
    "network is unreachable",
    "network dropped connection on reset",
    "software caused connection abort",
    "connection reset by peer",
    "no buffer space available",
    "socket is already connected",
    "socket is not connected",
    "can't send afer socket shutdown",
    "undefined error (59)",
    "connection timed out",
    "connection refused",
    "too many levels of symbolic links",
    "file name too long",
    "host is down",
    "host is unreachable",
    "directory not empty",
    "too many processes",
    "too many users",
    "disk quota exceeded",
    "stale remote file handle",
    "pathname hit remote file system",
    "undefined error (72)",
    "undefined error (73)",
    "undefined error (74)",
    "undefined error (75)",
    "undefined error (76)",
    "identifier removed",
};

#endif
