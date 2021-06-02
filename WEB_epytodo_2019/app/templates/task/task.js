<script type="text/javascript">
    $('#addtask-button').on('click', function () {
        var add = $('#addtask-form');
        add.modal({
            onShow: function() {
                $('#begin-calendar').calendar({
                    ampm: false,
                    startMode: 'year'
                })
                $('#end-calendar').calendar({
                    ampm: false,
                    startMode: 'year'
                });
            }
        }).modal('show');
    });
    $('#delete-button').on('click', function () {
        var id = $(this).attr('idp');
        var mod = $('#delete-form');
        mod.modal('show');
        $('#confirm-delete').each(function () {
            var newUrl = "/user/task/del/";
            newUrl = newUrl.concat(id);
            $(this).attr("action", newUrl);
        })
    });
    $('.ui.dropdown').dropdown();
    $('.ui.calendar').calendar({
        ampm: false
    });
</script>