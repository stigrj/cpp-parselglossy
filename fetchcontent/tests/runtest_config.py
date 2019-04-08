from os import path
from sys import platform


def configure(options, input_files, extra_args):
    """
    This function configures runtest
    at runtime for code specific launch command and file naming.
    """

    launcher = 'pi'
    launcher_full_path = path.normpath(path.join(options.binary_dir, launcher))

    command = []
    command.append(launcher_full_path)
    command.append(input_files)

    if extra_args is not None:
        command.append(extra_args)

    full_command = ' '.join(command)

    inp_no_suffix = path.splitext(input_files)[0]
    output_prefix = inp_no_suffix

    relative_reference_path = 'reference'

    return launcher, full_command, output_prefix, relative_reference_path
