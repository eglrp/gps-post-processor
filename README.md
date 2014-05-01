* Michael Brandt
* Dominic Fuller-Rowell
* Waverly Hinton

Project for CSCI 4448: Object-Oriented Analysis and Design, Spring 2014 at University of Colorado Boulder. Instructors [Dana Hughes](https://github.com/danathughes) and Liz Boese.

Online Files
* [Project Part 2 Write-up on Google Drive](https://docs.google.com/document/d/11ZYlaCbc_-gzKwfqhztlTY8-qe2mE0jQOBmyxXgaEPE)
* [Project Part 4 Write-up on Google Drive](https://docs.google.com/document/d/1yLMd5OnVX_YpGLAsmxOOJYFe-SOqzFD0wAlEKY_cd3Y)
* [UML Class Diagram on draw.io](https://www.draw.io/#G0B1qTpXqWjW9sUVZBUms0VTJMQ1k)

Other links
* [Pivotal Tracker](https://www.pivotaltracker.com/s/projects/1056358)

### Using GPSTk

#### Working with pre-built library

(This probably only works on 64-bit Ubuntu 12, the OS setup on the CU CSCI VM)

The source is included in the repo as a tarball to keep the size smaller. It
will need to be extracted for the include paths to work correctly. To extract it
to a `gpstk/` directory:
```
cd diff-gps/
tar xvzf gpstk-2.1.src.tar.gz
```
* `ls gpstk/` to list the contents and confirm the `tar` command worked

You must copy `libgpstk.so` into `/usr/lib`:

`sudo cp diff-gps/gpstk-build/libgpstk.so /usr/lib`

#### Building from Scratch

Directions adapted from [gpstk.org](http://www.gpstk.org/bin/view/Documentation/BuildingGPSTkUnderUnix).

Prerequisites:
* CMake; check with `cmake --version`. GPSTk docs don't specify a version.
* g++ version 4.7.3 (part of the [GNU Compiler Collection](http://gcc.gnu.org/)); check with `g++ --version`

```
cd diff-gps/
tar xvzf gpstk-2.1.src.tar.gz
mkdir gpstk-build/
cd gpstk/
mkdir build/
cd build/
cmake -DCMAKE_INSTALL_PREFIX:PATH=../../gpstk-build/ ../
make
make install
cp src/libgpstk.so ../../gpstk-build/
cd ../../
sudo cp gpstk-build/libgpstk.so /usr/lib/
```
