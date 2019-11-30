#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag;

int main (int argc, char **argv)
{
  int c;
  int aopt = 0, bopt = 0, lflag = 0, fflag = 0;
  char *lopt = 0, *fopt = 0;

  while (true)
    {
      static struct option long_options[] =
        {
          /* These options set a flag. */
          {"verbose", no_argument,       &verbose_flag, 1},
          /* These options don’t set a flag.
             We distinguish them by their indices. */
          {"a_option",     no_argument,       0, 'a'},
          {"b_option",  no_argument,       0, 'b'},
          {"list",  required_argument, 0, 'l'},
          {"file",    required_argument, 0, 'f'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "abl:f:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
	  if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'a':
	  if (aopt == 0) {
          	puts ("option -a");
		aopt = 1;
	  }
          break;

        case 'b':
	  if (bopt == 0) {
          	puts ("option -b");
		bopt = 1;
	  }
          break;

        case 'l':
	  if (lflag == 0) {
          	printf ("option -l with value `%s'\n", optarg);
		lflag = 1;
        	lopt = optarg;
	  }	
	  break;

        case 'f':
	  if (fflag == 0) {
          	printf ("option -f with value `%s'\n", optarg);
          	fflag = 1;
		fopt = optarg;
	  }	
	  break;


        case '?':
          break;

        default:
          abort ();
        }
    }

  if (verbose_flag)
    puts ("\nverbose flag is set");

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
