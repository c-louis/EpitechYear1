<script type="text/javascript">
    $('#login-button').on('click', function () {
        var login = $('#login-form');
        login.modal('show');
    })
    $('#register-button').on('click', function () {
        var register = $('#register-form');
        register.modal('show');
    })
    $('#logout-button').on('click', function () {
        var logout = $('#logout-form');
        logout.modal('show');
    })
    $('#menu-button').dropdown();
</script>