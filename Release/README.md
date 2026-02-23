# Precompiled Firmware
The firmware is now handled and installed to RNodes directly through `rnodeconf`, which is inclueded in the `rns` package. It can be installed via `pip`:

```
# Install rnodeconf via rns package
pip install rns --upgrade

# Install the firmware on a board with the install guide
rnodeconf --autoinstall
```
