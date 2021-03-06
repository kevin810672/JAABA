% change in angle to closest point on wall in fly's coordinate system
function [data,units] = compute_dangle2closestroi2(trx,n)

flies = trx.exp2flies{n};
nflies = numel(flies);
data = cell(1,nflies);
for i = 1:nflies,
  fly = flies(i);  
  % set sign so that negative means going toward 0, positive means going
  % away from 0
  if trx(fly).nframes <= 1,
    data{i} = [];
  else
    data{i} = sign(trx(fly).angle2closestroi2(1:end-1)).*...
      modrange(diff(trx(fly).angle2closestroi2,1,2),-pi,pi)./trx(fly).dt;
  end
end
units = parseunits('rad/s');

