--[[
--�������ʧ�ܣ��ؼ��ڲ��Ჶ�񣬲�����һ�����ַ�����
--��Ͳ�֪����ʧ�ܻ��Ǳ��ӿڱ����ͷ�����nil��������ñ�֤����
--���ӿڲ�Ҫʧ�ܣ�
function FormatXCoordinate(Address, DateTime, Action) --���1
return nil
end
--]]

--�������ʧ�ܣ��ؼ��ڲ��Ჶ�񣬲�����һ�����ַ�����
--��Ͳ�֪����ʧ�ܻ��Ǳ��ӿڱ����ͷ�����nil��������ñ�֤����
--���ӿڲ�Ҫʧ�ܣ�
function FormatYCoordinate(Address, Value, Action) --���2
	if 1 == Action --���������Ὺʼ
		then
	elseif 2 == Action --���������������
		then
		return string.format("%.1f kw", Value)
	elseif 3 == Action --�������������
		then
	elseif 4 == Action --��ʾ������ʾ��Tooltip��
		then
		return string.format("%.2f Y������ʾ(lua)", Value)
	elseif 5 == Action --��������
		then
		return string.format("%.2f ����Y����", Value)
	elseif 6 == Action --����Y��λ��ʱ���ã������action����2ʱ����ֵ��һ�������߸���Ҳ��
		then
		return string.format("%.1f kw ", Value) --�������һ���ո����action����2ʱ�������ǿ��Ե�
		--[[
		������һ�����ɣ����ﷵ�ص��ַ�������������������һ�����ȣ��Ա�ȷ��Y���λ��
		��������ȫ���Է��������ַ�������Ϊ�����������������ģ��ַ������ݲ�û��ʲô����
		����������ɣ�����������ﷵ�غ㶨���ַ��������䳤��Ҳ���Ǻ㶨�ģ�����Y�����ʾλ��Ҳ���Ǻ㶨����
		�㻹���Է��ر�Action����2ʱ���ص��ַ�������������������Y������Y��ճ���һ���ľ���
		--]]
	elseif 7 == Action --�������ֵ
		then
		return string.format("%.0f", Value) --���۾����Ƕ��٣�����ʾ������λ
	end
end

--�������ʧ�ܣ������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
function TrimXCoordinate(DateTime) --���3
	--����ǿؼ��ڲ���ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
	--���ο�������ȫ���������޸�
	return tonumber(string.format("%.0f", DateTime + .5)) --����������
end

--�������ʧ�ܣ������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
function TrimYCoordinate(Value)  --���4
	--����ǿؼ��ڲ���ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
	--���ο�������ȫ���������޸�
	return tonumber(string.format("%.0f", Value + .5)) --����������
end

--����ǿؼ��ڲ���ʵʩ���ŵ�ʵ�֣��ڲ��������Ȼ����ʵ�֣���Ϊ�˺���ǰ���ݣ�
--���ο�������ȫ���������޸�
function GETSTEP(V, ZOOM)
	if (0 == ZOOM)
		then
		return V
	elseif (ZOOM > 0)
		then
		return V / (ZOOM * .25 + 1)
	else
		return V * (-ZOOM * .25 + 1)
	end
end

--�������ʧ�ܣ������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
function CalcTimeSpan(TimeSpan, Zoom, HZoom) --���5
	--������ʾһ����̬�÷����������ź����꣬����ʾ�����ʽ�������
	return TimeSpan;
	--�������ϵĴ�����
--	return GETSTEP(TimeSpan, Zoom + HZoom)
end

--�������ʧ�ܣ������ÿؼ��ڲ���Ĭ�ϴ���ʽ����
function CalcValueStep(ValueStep, Zoom)  --���6
	if (Zoom > 0) --������ʾһ���Զ��������ٶȣ����Ŵ�ʱ�����ǷŴ�Zoom���������ǿؼ�Ĭ�ϵ�1/4��
		then
		return ValueStep / (Zoom + 1)
	else
		return ValueStep * (-Zoom + 1)
	end

	--�������ϵĴ�����
--	return GETSTEP(ValueStep, Zoom);
end
--����ϸ���÷��ο�ST_Curve_PlugIn.hppͷ�ļ�
--print(FormatYCoordinate(0, 100.9, 2))

