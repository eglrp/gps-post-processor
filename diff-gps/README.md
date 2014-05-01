* Michael Brandt
* Dominic Fuller-Rowell
* Waverly Hinton

Project for CSCI 4448: Object-Oriented Analysis and Design, Spring 2014 at University of Colorado Boulder. Instructors [Dana Hughes](https://github.com/danathughes) and Liz Boese.

### Compilation/Running Instructions for final submission

* `libgpstk.so` was built in the [CU CSCI VM](http://foundation.cs.colorado.edu/sde/), so this likely won't work in any other environment. If you do want to build it in another environment, you will need to compile GPSTk for yourself. See our [github main page](https://github.com/michaeljb/gps-post-processor) for more information.

```
sudo cp gpstk-build/libgpstk.so /usr/lib
make
build/GpsPostProcessor
```

This will run GpsPostProcessor's main function, which goes through some examples of converting units and processing RINEX data.
