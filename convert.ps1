$files = Get-Item *.jpg

foreach ($f in $files)
{
    # �~�b�v���x��
    $mipLevel = 2  

    $arguments = @(
        $f.FullName,
        "-ml", $mipLevel
        # ���̈�����ǉ��ł��܂�
    )

    Start-Process -FilePath "TextureConverter.exe" -ArgumentList $arguments -Wait
}
pause