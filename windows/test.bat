@echo OFF
FOR /L %%A IN (1,1,200) DO (
  echo testing on test %%A
  gen.exe %%A > in
  a.exe < in > out
  brute.exe < in > outexpected
  FC /w /n  out outexpected >NUL && Echo Same || PAUSE
)