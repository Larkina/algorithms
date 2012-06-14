program project1;

{$mode objfpc}{$H+}

uses
  Classes,
  SysUtils;

{$R *.res}

type
  pair = record
    op: char;
    num: integer;
  end;

const
  inf: integer = 1000000;
  maxn: integer = 1000;

var
  n, i, j, t, k: integer;
  nums: array[0 .. 1000] of integer;
  res: array[0 .. 1000, -1000 .. 1000] of pair;
  ans: array[0 ..1000] of char;

begin
  Assign(input, 'input.txt');
  reset(input);
  Assign(output, 'output.txt');
  rewrite(output);
  n := 0;
  while (not EOF()) do
  begin
    Read(nums[n]);
    Inc(n);
  end;
  Dec(n);
  for i := 0 to n - 1 do
    for j := -maxn to maxn do
      res[i, j].num := inf;
  res[0, nums[0]].num := 0;
  for i := 0 to n do
    for j := -maxn to maxn do
      if (res[i, j].num <> inf) then begin
        if (abs(j + nums[i + 1]) <= maxn) then begin
          res[i + 1, j + nums[i + 1]].op := '+';
          res[i + 1, j + nums[i + 1]].num := j;
        end;
        if (abs(j - nums[i + 1]) <= maxn) then begin
          res[i + 1, j - nums[i + 1]].op := '-';
          res[i + 1, j - nums[i + 1]].num := j;
        end;
        if (abs(j * nums[i + 1]) <= maxn) then begin
          res[i + 1, j * nums[i + 1]].op := '*';
          res[i + 1, j * nums[i + 1]].num := j;
        end;
        if (nums[i + 1] <> 0) and (abs(j div nums[i + 1]) <= maxn) then begin
          res[i + 1, j div nums[i + 1]].op := '/';
          res[i + 1, j div nums[i + 1]].num := j;
        end;
      end;
   i := n - 1;
   j := nums[n];
   t := res[i, j].num;
   k := 0;
   while (i > 0) and (t <> inf) and (t <> 0) do begin
     ans[k] := res[i, j].op;
     j := t;
     dec(i);
     t := res[i, j].num;
     inc(k);
   end;
   if (t = inf) then
      write('IMPOSSIBLE')
   else begin
        for i := k - 1 downto 0 do
          write(ans[i]);
   end;
end.

