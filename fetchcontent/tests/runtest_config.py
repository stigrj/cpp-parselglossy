from os import path
from sys import platform
import subprocess


def configure(options, input_files, extra_args):
    """
    This function configures runtest
    at runtime for code specific launch command and file naming.
    """

    fr_file = 'pi.json'
    tp_file = '../../../src/template.yml'
    grammar = 'getkw'

    # Running parselglossy CLI: pi.inp -> pi.json
    parsel_command = []
    parsel_command.append('parselglossy')
    parsel_command.append('parse')
    parsel_command.append('--outfile=' + fr_file)
    parsel_command.append('--template=' + tp_file)
    parsel_command.append('--grammar=' + grammar)
    parsel_command.append(input_files)
    subprocess.call(parsel_command)

    # Running C++ executable
    launcher = 'pi'
    launcher_full_path = path.normpath(path.join(options.binary_dir, launcher))

    command = []
    command.append(launcher_full_path)
    command.append(fr_file)

    if extra_args is not None:
        command.append(extra_args)

    full_command = ' '.join(command)
    output_prefix = path.splitext(input_files)[0]
    relative_reference_path = 'reference'

    return launcher, full_command, output_prefix, relative_reference_path
