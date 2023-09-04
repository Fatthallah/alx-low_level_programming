#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>


void prt_abii(unsigned char *e_id);
void prt_sabii(unsigned char *e_id);
void prt_dta(unsigned char *e_id);
void prt_tpe(unsigned int e_tpe, unsigned char *e_id);
void prt_vrs(unsigned char *e_id);
void chk_elf(unsigned char *e_id);
void prt_clss(unsigned char *e_id);
void prt_ety(unsigned long int e_ety, unsigned char *e_id);
void prt_mgc(unsigned char *e_id);
void cls_elf(int elf);

/**
 * chk_elf - Checks file for an ELF.
 * @e_id: ELF numbers.
 *
 * Description: not ELF - 98.
 */

void chk_elf(unsigned char *e_id)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_id[idx] != 127 &&
		    e_id[idx] != 'E' &&
		    e_id[idx] != 'L' &&
		    e_id[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prt_mgc - The Magic Number will be printed.
 * @e_id: Array.
 *
 * Description: Sepsaraation.
 */

void prt_mgc(unsigned char *e_id)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_id[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prt_clss - to be printed.
 * @e_id: Array.
 */

void prt_clss(unsigned char *e_id)
{
	printf(" Class: ");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * prt_dta - Print.
 * @e_id: Array
 */

void prt_dta(unsigned char *e_id)
{
	printf(" Data: ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 *  * prt_vrs - the version to be printed.
 *   * @e_id: Array.
 *
 */

void prt_vrs(unsigned char *e_id)
{
	 printf(" Version: %d", e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * prt_sabii - OS/ABI.
 * @e_id: array.
 */

void prt_sabii(unsigned char *e_id)
{
	printf(" OS/ABI: ");

	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

/**
 * prt_abii - abi.
 * @e_id: array.
 */

void prt_abii(unsigned char *e_id)
{
	printf(" ABI Version: %d\n", e_id[EI_ABIVERSION]);
}

/**
 * prt_tpe - type.
 * @e_tpe: type.
 * @e_id: array.
 */

void prt_tpe(unsigned int e_tpe, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_tpe >>= 8;

	printf(" Type: ");

	switch (e_tpe)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_tpe);
	}
}

/**
 * prt_ety - Prints.
 * @e_ety: addres.
 * @e_id: array
 */

void prt_ety(unsigned long int e_ety, unsigned char *e_id)
{
	printf(" Entry point address: ");

	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_ety = ((e_ety << 8) & 0xFF00FF00) |
			  ((e_ety >> 8) & 0xFF00FF);
		e_ety = (e_ety << 16) | (e_ety >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_ety);

	else
		printf("%#lx\n", e_ety);
}

/**
 * cls_elf - this Closes
 * @elf: Tjj
 *
 * Description: 98.
 */

void cls_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - jjjjjjjjjjjjjjxxxxxxxx
 * @agc: kkkkkkkkkkkkkk
 * @agv: lllllllllllllll
 *
 * Return: 0 if success.
 *
 * Description: llllppppppppp
 * if fails - 98.
 */

int main(int __attribute__((__unused__)) agc, char *agv[])
{
	Elf64_Ehdr *header;
	int rr;
	int oo;

	oo = open(agv[1], O_RDONLY);
	if (oo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", agv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		cls_elf(oo);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", agv[1]);
		exit(98);
	}
	rr = read(oo, header, sizeof(Elf64_Ehdr));
	if (rr == -1)
	{
		free(header);
		cls_elf(oo);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", agv[1]);
		exit(98);
	}

	chk_elf(header->e_ident);
	printf("ELF Header:\n");
	prt_mgc(header->e_ident);
	prt_clss(header->e_ident);
	prt_dta(header->e_ident);
	prt_vrs(header->e_ident);
	prt_sabii(header->e_ident);
	prt_abii(header->e_ident);
	prt_tpe(header->e_type, header->e_ident);
	prt_ety(header->e_entry, header->e_ident);

	free(header);
	cls_elf(oo);
	return (0);
}
